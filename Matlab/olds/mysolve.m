function y = mysolve(x0,d,u)
f = @(x)myfun(x,d,u);
y = fsolve(f,x0);

function F = myfun(x,d,u)
F = [u(1)-sqrt(((cos(1/3.*pi+x(3))*cos(x(2))-sin(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(d(4))+sin(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(d(4))-d(2)*cos(d(3))+x(4))^2+ ((sin(1/3.*pi+x(3))*cos(x(2))+cos(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(d(4))-cos(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(d(4))-d(2)*sin(d(3))+x(5))^2+ (-cos(x(1))*sin(x(2))*d(1)*cos(d(4))-sin(x(1))*d(1)*sin(d(4))+d(5)+x(6))^2)
     u(2)-sqrt(((cos(1/3.*pi+x(3))*cos(x(2))-sin(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(d(4))-sin(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(d(4))+d(2)*cos(1/3.*pi+d(3))+x(4))^2+ ((sin(1/3.*pi+x(3))*cos(x(2))+cos(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(d(4))+cos(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(d(4))-d(2)*sin(1/3.*pi+d(3))+x(5))^2+ (-cos(x(1))*sin(x(2))*d(1)*cos(d(4))+sin(x(1))*d(1)*sin(d(4))+d(5)+x(6))^2)
     u(3)-sqrt((-(cos(1/3.*pi+x(3))*cos(x(2))-sin(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(1/3.*pi+d(4))-sin(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(1/3.*pi+d(4))+d(2)*sin(1/6.*pi+d(3))+x(4))^2+(-(sin(1/3.*pi+x(3))*cos(x(2))+cos(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(1/3.*pi+d(4))+cos(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(1/3.*pi+d(4))-d(2)*cos(1/6.*pi+d(3))+x(5))^2+(cos(x(1))*sin(x(2))*d(1)*cos(1/3.*pi+d(4))+sin(x(1))*d(1)*sin(1/3.*pi+d(4))+d(5)+x(6))^2)
     u(4)-sqrt((-(cos(1/3.*pi+x(3))*cos(x(2))-sin(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*sin(1/6.*pi+d(4))-sin(1/3.*pi+x(3))*cos(x(1))*d(1)*cos(1/6.*pi+d(4))+d(2)*sin(1/6.*pi+d(3))+x(4))^2+(-(sin(1/3.*pi+x(3))*cos(x(2))+cos(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*sin(1/6.*pi+d(4))+cos(1/3.*pi+x(3))*cos(x(1))*d(1)*cos(1/6.*pi+d(4))+d(2)*cos(1/6.*pi+d(3))+x(5))^2+(cos(x(1))*sin(x(2))*d(1)*sin(1/6.*pi+d(4))+sin(x(1))*d(1)*cos(1/6.*pi+d(4))+d(5)+x(6))^2)
     u(5)-sqrt((-(cos(1/3.*pi+x(3))*cos(x(2))-sin(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*sin(1/6.*pi+d(4))+sin(1/3.*pi+x(3))*cos(x(1))*d(1)*cos(1/6.*pi+d(4))+d(2)*cos(1/3.*pi+d(3))+x(4))^2+(-(sin(1/3.*pi+x(3))*cos(x(2))+cos(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*sin(1/6.*pi+d(4))-cos(1/3.*pi+x(3))*cos(x(1))*d(1)*cos(1/6.*pi+d(4))+d(2)*sin(1/3.*pi+d(3))+x(5))^2+(cos(x(1))*sin(x(2))*d(1)*sin(1/6.*pi+d(4))-sin(x(1))*d(1)*cos(1/6.*pi+d(4))+d(5)+x(6))^2)
     u(6)-sqrt((-(cos(1/3.*pi+x(3))*cos(x(2))-sin(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(1/3.*pi+d(4))+sin(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(1/3.*pi+d(4))-d(2)*cos(d(3))+x(4))^2+(-(sin(1/3.*pi+x(3))*cos(x(2))+cos(1/3.*pi+x(3))*sin(x(1))*sin(x(2)))*d(1)*cos(1/3.*pi+d(4))-cos(1/3.*pi+x(3))*cos(x(1))*d(1)*sin(1/3.*pi+d(4))+d(2)*sin(d(3))+x(5))^2+(cos(x(1))*sin(x(2))*d(1)*cos(1/3.*pi+d(4))-sin(x(1))*d(1)*sin(1/3.*pi+d(4))+d(5)+x(6))^2)];  
  

 