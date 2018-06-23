# Drill 2
Write three functions ```swap_v(int,int)```, ```swap_r(int&, int&)```, and ```swap_crp(const int&, const int&)```. Each should have the body

```{int temp; temp = a, a = b; b = temp}```

where ```a``` and ```b``` are the names of the arguments.

Try calling each swap like this
* ```int x = 7;```
* ```int y = 9; ```
* ```swap_?(7,9);```
* ```const int cx = 7```
* ```const int cy = 9;```
* ```swap_?(cx,cy);```
* ```swap_?(7.7,9.9);```
* ```double dx = 7.7;```
* ```double dy = 9.9;```
* ```swap_?(dx,dy);```
* ```swap_?(dx,dy);```

Which calls compiled, and why? After each swap that compiled, print the value of the arguements after the call to see if they were actually swapped. If you are surprised by a result, consult section 8.6
