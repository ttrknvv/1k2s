%Вариант 9
%Интерполяционный многочлен Ньютона
clear
clc
format long

a = 1;
b = 3;
syms  sim; %создаём символьную переменную
tiledlayout(2,4); % количество графиков( кол-во строк и колонок)
p = linspace(1, 3, 100);
r = 1 / (5 * sin(3*p)^2 + 2* cos(3*p)^2);

for i = 3:9;
    h = (b-a)./i; %шаг
    x = a:h:b; %делим промежуток на одинаковые части
    y = 1 / (5 * sin(3*x)^2 + 2* cos(3*x)^2);
    hold on; 
    i
    Newton = newton(sim, x, y, i);
    Newton = sym2poly(Newton) %выставление коэффициентов
    check = polyfit(x,y,i  )
    Y = polyval(Newton,p);
    nexttile; plot(p, Y, 'b');hold on; plot(p, r, 'r');
    hold on; plot(x, y, '*m') ;%графики на разных изображениях
    disp('- - - - - - - - - - - - - - - - - - - - - - - - - - - - -')
end

legend('Полиномы Ньютона','Данная функция','Точки интерполяции' )
hold on;
p = linspace(1, 2, 100);
q = 1 / (5 * sin(3*p)^2 + 2* cos(3*p)^2);
nexttile;
plot(p, q, 'r'); %график функции

%Ньютон
function output = newton(x, xi, yi,ni) %универсальная функция для нахождения разных степеней
    output = yi(1);
    for i = 1:ni
        q = 1;
        for j = 1:i
            q = q.*(x - xi(j));
        end
        output = output +q*divided_difference(1, i+1, xi, yi);
    end
end
%Вычисление разделённой разности
function output = divided_difference(i1, i2, x, f)
    if i2-i1==1
        output = (f(i2)-f(i1))/(x(i2)-x(i1));
    else
        output = (divided_difference(i1 + 1, i2, x, f) - divided_difference(i1, i2 -1, x, f))/(x(i2) - x(i1));
    end
end