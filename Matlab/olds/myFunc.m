function a = myFunc(u,d,x0)
a = fsolve(@(x) fonction(x,u,d),x0);
end