#include <Windows.h>
#include <wincrypt.h>
#include <stdio.h>

// This blog post shows how to use the CertCreateCertificateContext function to create a certificate context from a DER-encoded certificate.

// The CertCreateCertificateContext function takes three parameters: the encoding type, a pointer to the certificate data, and the size of the certificate data. It returns a pointer to a CERT_CONTEXT structure that contains information about the certificate, such as the issuer name, the subject name, and the public key.

// The following code snippet demonstrates how to use the CertCreateCertificateContext function to create a certificate context from a file that contains a DER-encoded certificate. The file name is passed as a command-line argument to the program.

int main(int argc, char* argv[])
{
    // Check if the file name is provided
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Open the file in binary mode
    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        printf("Error: cannot open file %s\n", argv[1]);
        return -1;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    DWORD cbCert = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the certificate data
    BYTE* pbCert = (BYTE*)malloc(cbCert);
    if (pbCert == NULL)
    {
        printf("Error: cannot allocate memory\n");
        fclose(fp);
        return -1;
    }

    // Read the certificate data from the file
    if (fread(pbCert, 1, cbCert, fp) != cbCert)
    {
        printf("Error: cannot read file %s\n", argv[1]);
        free(pbCert);
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Create a certificate context from the certificate data
    PCCERT_CONTEXT pCertContext = CertCreateCertificateContext(X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, pbCert, cbCert);
    if (pCertContext == NULL)
    {
        printf("Error: cannot create certificate context. Error code: %u\n", GetLastError());
        free(pbCert);
        return -1;
    }

    // Print some information about the certificate
    printf("Certificate information:\n");
    printf("Issuer: %S\n", pCertContext->pCertInfo->Issuer.pbData);
    printf("Subject: %S\n", pCertContext->pCertInfo->Subject.pbData);
    printf("Serial number: %S\n", pCertContext->pCertInfo->SerialNumber.pbData);

    // Free the certificate context and the certificate data
    CertFreeCertificateContext(pCertContext);
    free(pbCert);

    return 0;
}
