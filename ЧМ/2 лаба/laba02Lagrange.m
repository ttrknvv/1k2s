%Вариант 9
%Интерполяционный полином Лагранжа
clear
clc
format long

a = 1;
b = 3;
syms  sim; % символьная переменная
tiledlayout(2,4); % количество графиков( кол-во строк и колонок)
p = linspace(1, 3, 100); % промежуток от 1 до 3, 100 точек
r = 1 / (5 * sin(3*p)^2 + 2* cos(3*p)^2); %данная функция

for n = 3:9; %степень
    h = (b-a)./n; %шаг
    x = a:h:b; %делим промежуток на одинаковые части
    y = 1 / (5 * sin(3*x)^2 + 2* cos(3*x)^2);
    n
    Lagrange = lagrange(sim, x, y, n); % вызов функции
    Lagrange = sym2poly(Lagrange)%функция, выводящая коэффициенты, чтобы не было дробей
    correct = polyfit(x,y,n) %точки интерполяции
    Y = polyval(Lagrange,p);
    nexttile; plot(p, Y, 'b');hold on; plot(p, r, 'r'); hold on; plot(x, y, '*m') ;%графики на разных изображениях
end

legend('Полиномы Лагранжа','Данная функция','Точки интерполяции' )
hold on;
p = linspace(1, 2, 100);
q = 1 / (5 * sin(3*p)^2 + 2* cos(3*p)^2);
nexttile;
plot(p, q, 'r'); %график функции

function output = lagrange(x, xi, yi,ni) %универсальная функция для нахождения разных степеней
    output = 0;
    for i = 1:ni + 1
        l = 1;
        for j = 1:ni + 1
            if j~=i
                l = l.*(x-xi(j))/(xi(i)-xi(j));
            end
        end
        output = output +yi(i)*l;
    end
end