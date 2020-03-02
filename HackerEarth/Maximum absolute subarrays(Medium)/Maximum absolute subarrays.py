### https://www.hackerearth.com/challenges/competitive/data-structures-and-algorithms-coding-contest-7/algorithm/maximum-absolute-sub-array/


# Modified Kadane's algo - for dynamic programming
# Based on max-sum subarray

n = int(input())
arr = list(map(int,input().split()))


left_pos = [arr[0]]             # array to track positive sum in left to right traversal
left_neg = [arr[0]]             # array to track negative sum in left to right traversal

right_pos = [arr[n-1]]          # array to track positive sum in right to left traversal
right_neg = [arr[n-1]]          # array to track negative sum in right to left traversal



# left to right traversal
for i in range(1, n):
    tmp = max(0, arr[i], arr[i] + left_pos[i-1])
    left_pos.append(tmp)
    
    tmp = min(0, arr[i], arr[i] + left_neg[i-1])
    left_neg.append(tmp)
    
    
    
# right to left traversal
for i in range(n-2, -1, -1):
    tmp = max(0, arr[i], arr[i] + right_pos[n-i-2])
    right_pos.append(tmp)
    
    tmp = min(0, arr[i], arr[i] + right_neg[n-i-2])
    right_neg.append(tmp)



# reversing right to left traveral arrays to make indexing easier
right_pos.reverse()
right_neg.reverse()



# IDEA: divide subarray into positive and negative sum arrays
# adding left_positive_sum and right_negative_sum (divided subarras)
#               or
# adding left_negative_sum  and right_positive_sum
ans = 0
for i in range(n-1):
   tmp1 = max(abs(left_pos[i]), abs(right_neg[i+1]), abs(left_pos[i] - right_neg[i+1]))
   tmp2 = max(abs(left_neg[i]), abs(right_pos[i+1]), abs(left_neg[i] - right_pos[i+1]))
   ans = max(ans, tmp1, tmp2)
else:
    # for left-out edge cases
    ans = max(ans, abs(left_pos[n-1]), abs(left_neg[n-1]), abs(right_pos[0]), abs(right_pos[0]))

print(ans)
