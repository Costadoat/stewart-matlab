[m,n] = size(lmes);
result=zeros(m,6);
options = optimset('Display','off');
x0=[0,0,0,0,0,0];
tfin=lmes(m,1);
for idx = 1:m
    u=lmes(idx,2:7);
    d=[200 270 0.007 0.009 380];
    result(idx,1)=lmes(idx,1);
    a = fsolve(@(x) fonction(x,u,d),x0,options);
    x0=a;
    result(idx,2:7)=a;
end

figure('units','normalized','outerposition',[0 0 1 1])
ax1 = subplot(2,3,1); % top subplot
ax2 = subplot(2,3,2); % bottom subplot
ax3 = subplot(2,3,3); % bottom subplot
ax4 = subplot(2,3,4); % bottom subplot
ax5 = subplot(2,3,5); % bottom subplot
ax6 = subplot(2,3,6); % bottom subplot

colour_cons = [101 94 94] ./ 255;
colour_result = [0 108 255] ./ 255;

set(ax1, 'ColorOrder', [colour_result; colour_cons],'NextPlot', 'replacechildren');
set(ax2, 'ColorOrder', [colour_result; colour_cons],'NextPlot', 'replacechildren');
set(ax3, 'ColorOrder', [colour_result; colour_cons],'NextPlot', 'replacechildren');
set(ax4, 'ColorOrder', [colour_result; colour_cons],'NextPlot', 'replacechildren');
set(ax5, 'ColorOrder', [colour_result; colour_cons],'NextPlot', 'replacechildren');
set(ax6, 'ColorOrder', [colour_result; colour_cons],'NextPlot', 'replacechildren');

plot(ax1,result(:,1),result(:,2), result(:,1), cons(:,1))
ylabel(ax1,'Theta x')
plot(ax2,result(:,1),result(:,3), result(:,1), cons(:,2))
ylabel(ax2,'Theta y')
plot(ax3,result(:,1),result(:,4), result(:,1), cons(:,3))
ylabel(ax3,'Theta z')
plot(ax4,result(:,1),result(:,5), result(:,1), cons(:,4))
ylabel(ax4,'x')
plot(ax5,result(:,1),result(:,6), result(:,1), cons(:,5))
ylabel(ax5,'y')
plot(ax6,result(:,1),result(:,7), result(:,1), cons(:,6))
ylabel(ax6,'z')

axis([ax1 ax2 ax3],[0 tfin -0.5 0.5])
axis([ax4 ax5 ax6],[0 tfin -50 50])
