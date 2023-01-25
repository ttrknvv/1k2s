F = @(x) ( (acos(sqrt(2)* x)) ./ (sqrt(2-4*x.^2)) );
a = 2; % нижний предел 
b = 9; % верхний предел
n = 10; % количество частей
h = (b - a) / (2*n); % шаг разбиения
s1 = 0;
s2 = 0;
for I= 1:2:(2*n-1)
    x=a+h*I;
    s1=s1+F(x); % МЕТОД Симпсона(парабол)
end
for I= 2:2:(2*n-2)
    x=a+h*I;
    s2=s2+F(x); % МЕТОД Симпсона(парабол)
end
S=abs(h*(F(a)+4*s1+2*s2+F(b))/3); % конечный результат

t = sym("x");
f = (acos(sqrt(2)* t) ./ (sqrt(2-4*t.^2))); % ТОЧНОЕ ЗНАЧЕНИЕ
tochnii = int(f, 2, 9);

c = abs((tochnii - S) / tochnii * 100); % погрешность
absolute = abs((tochnii - S));

disp('Cимпсона: '), disp(double(S));
disp('Точный: '), disp(double(tochnii));
disp('Погрешность: '), disp(double(c));
disp('Погрешность abs: '), disp(double(absolute));