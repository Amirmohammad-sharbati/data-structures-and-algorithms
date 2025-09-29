import bisect # This is for binary search

values = [int(x) for x in input().split()]
n = values[0]
q = values[1]
numbers = []
numbers = [int(x) for x in input().split()]

number_to_its_index = {} 
for i in range(n) : # I have dict from number to its indices+1
    number_to_its_index.setdefault(numbers[i], []).append(i + 1)

# get queries
for i in range(q):
    values = [int(x) for x in input().split()]
    r = values[0]
    l = values[1]
    if(r==l):
        print(numbers[r-1])
        continue
    
    half_length = (l-r+1)//2
    
    # checking the first number
    number = numbers[r-1]
    left_index = bisect.bisect_left(number_to_its_index[number], r)
    right_index = bisect.bisect_right(number_to_its_index[number], l)
    # Each bisect_left or bisect_right operation takes O(log n) time since it's a binary search.
    if(right_index - left_index > half_length):
        print(number)
        continue
    
    # checking the middle number
    number = numbers[r+((l-r-1)//2)]
    left_index = bisect.bisect_left(number_to_its_index[number], r)
    right_index = bisect.bisect_right(number_to_its_index[number], l)
    if(right_index - left_index > half_length):
        print(number)
        continue
    
    # If first number or middle number wasn't answer, so we don't have answer.
    else : print(0)
    # At first I want to implement random algorithm, after some checkings I came to this conclusion.