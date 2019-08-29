function y = mysolve(x0,c)
f = @(x)myfun(x,c);
y = fsolve(f,x0);

function F = myfun(x,c)
F = [ 2*x(1) - x(2) - exp(c*x(1))
    -x(1) + 2*x(2) - exp(c*x(2))];  
