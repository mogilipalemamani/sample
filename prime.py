num=input("enter num:")
print(num)
i=2
while i<num:
    if num%i==0:
        print num,"is not a prime"
        break
    i+=1
else:
    print num,"is prime"
