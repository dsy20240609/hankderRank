i have design the algorithm as two level loop, one for one while. because i think if you have two effective number, you need to contine swap
 
 i = 0 3 1 4 -1
 i = 0 4 1 3 -1
 i = 0 -1 1 3 4
 i = 1 1 -1 3 4
 i = 1 1 -1 3 4 don't swap, move on
 i =2  1 -1 3 4

if the current number is not effective, move on,
if the number to be swap is effective, swap, then i didn't increase, so contine to checkt the current number, continue step 2
if the number to be swap if non effective, swap, then return two step 1 

i = 0 1 1
i = 1 1 