import math
def prime_check(number):
  is_prime = True

  for i in range(2,int(math.sqrt(number))+1):
    if number % i == 0:
      is_prime = False
      continue
  return is_prime

enteredNumber = int(input("please enter a number:"))

largest_prime = 1

for i in range (2, int(math.sqrt(enteredNumber))):
  if enteredNumber % i ==0 and prime_check(i):
    largest_prime = i
  
print(largest_prime)

