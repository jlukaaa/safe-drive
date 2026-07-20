brojevi  = [x for x in range(1, 101) if sum (int(cifra) for cifra in str(x)) % 5 == 0]
print("Brojevi do 1 do 100 ciji je zbir cifara djeljiv sa 5 su: ")
print(brojevi)