format long;
%Уравнение и диапазон
F = @(x) x.^3 + 5.5 * x - 2;
x = linspace(-2, 2);
y0 = 0 * x; %просто прямая y = 0, чтобы было наглядней
del = 0.01; %погрешность


%График и его оформление
plot(x, F(x), 'r')
xlabel('Координата X');
ylabel('Координата Y');
hold on
plot(x, y0, 'black--')
legend('x^3+5.5x-2', 'y = 0'); 
grid on;

%Метод Ньютона (метод касательных)

a = -1; b = 1; %переопределение отрезка, чтобы не использовать
                %доп. переменные
der = derivative(); %вызов производной 1-го порядка
der2 = derivative2(); %вызов производной 2-го порядка

%Начальное приближение
temp = 0.34;
xn = temp - (F(temp) ./ der(temp)); %считаем первое приближение

while(abs(temp - xn) > del) %пока не достигнем необходимой точности, будет продолжать вычислять
    temp = xn;
    xn = temp - (F(temp) ./ der(temp)); %непосредственно формула Ньютона
end

disp('Корень уравнения с помощью метода Ньютона');
disp(xn)
%Первая производная функции
function der = derivative() 
    syms x;
    f = x.^3 + 6 * x + 3;
    syms der;
    der = matlabFunction(diff(f));
end

%Вторая производная функции
function der2 = derivative2() 
    syms x;
    f = x.^3 + 6 * x + 3;
    syms der2;
    der2 = matlabFunction(diff(f, 2));
    end