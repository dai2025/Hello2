from sha3 import SHA3_256
h = SHA3_256()
h.update(b"Hello world")
print(h.hexdigest())
