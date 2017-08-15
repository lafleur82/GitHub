
#sieve of Eratosthenes
nums = list(range(2, 122))
first = 2
i = 0
while first < len(nums):
    for np in nums:
        if np > first and np % first == 0:
            nums.remove(np)
    i += 1
    first = nums[i]

print(nums)
