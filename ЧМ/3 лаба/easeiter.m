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

%Метод простой итерации
a = -1; b = 1; %переопределение отрезка, чтобы не использовать
                %доп. переменные
x0 = (a + b) ./ 2; %просто начальное приближение
M = @(x0) 1.01 .* der(x0); %некоторая постоянная
f = @ (x) x - F(x) ./ M(x); % φ(x) - как в методичке

%Сам метод (подставляем новое значение в функцию и т.д.)
x0 = f(x0);
while(abs(x0 - f(x0)) > del)
    x0 = f(x0);    
end

disp('Корень уравнения с помощью метода простых итераций');
disp(x0);


    

