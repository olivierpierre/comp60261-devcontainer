#!/usr/bin/python3

import time

N = 100_000_000  # 100 million

# Create the list
arr = list(range(N))  # [0, 1, 2, ..., N-1]

# Start timer
start = time.time()

# Sum with bounds-checked access
sum = 0
for i in range(N):
    sum += arr[i]  # Bounds check every time

# End timer
end = time.time()

print("Sum =", sum)
print("Time = {:.3f} "
  "seconds".format(end - start))