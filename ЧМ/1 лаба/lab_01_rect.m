F = @(x) (acos(sqrt(2)* x) ./ (sqrt(2-4*x.^2)));
a = 2; % нижний предел 
b = 9; % верхний предел
n = 10; % количество частей
h = (b - a) / n; % шаг разбиения
S = 0;
for I= 0:n-1
    x = a + h / 2 + I*h;
    S = S + F(x); % МЕТОД СРЕДНИХ ПРЯМОУГОЛЬНИКОВ
end
finish = S * h; % конечный результат

t = sym("t");
f = (acos(sqrt(2)* t) ./ (sqrt(2-4*t.^2))); % ТОЧНОЕ ЗНАЧЕНИЕ
tochnii = int(f, 2, 9);

c = abs((tochnii - finish) / tochnii * 100); % погрешность
absolute = abs((tochnii - finish));

disp('Прямоугольником: '), disp(double(finish));
disp('Точный: '), disp(double(tochnii));
disp('Погрешность: '), disp(double(c));
disp('Погрешность abs: '), disp(double(absolute));


