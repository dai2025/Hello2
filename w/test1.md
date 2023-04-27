In this blog post, I will show you how to use the set command in Windows batch files to get user input and perform arithmetic operations. The set command can assign a value to a variable or modify an existing variable. To get user input, we can use the /p option and specify a prompt message. For example, the following line will ask the user to enter a value and store it in the variable num:

set /p num=Enter a value: 

To perform arithmetic operations, we can use the /a option and specify an expression. The expression can use operators such as +, -, *, /, and %. The % operator returns the remainder of a division. For example, the following line will divide the value of num by 2 and store the remainder in the variable mod:

set /a mod=num %% 2

Note that we need to use two percent signs (%%) to escape the special meaning of the % symbol in batch files. Otherwise, it will be interpreted as a variable name. To display the value of a variable, we can use the echo command with a percent sign before and after the variable name. For example, the following line will print the value of mod:

echo %mod%

I hope this blog post was helpful for you to learn how to use the set command in batch files. If you have any questions or feedback, please leave a comment below.
