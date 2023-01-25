%график
%2 задание
% 2*y - cos(x+1)= 0
% x + sin(y) = -0.4
clear, clc
y1 = ezplot('2*y - cos(x+1) + 0.4');
set(y1);
hold on;
y2 = ezplot('x + sin(y)');
set(y2);
grid on;

%решение
x0 = -0.3; %точки полученные графически
y0 = 0.35; 
x = -0.4 - sin(y0);  
y = cos(x0+1)/2;
e = 0.01; %точность

k = 0; %счетчик итераций
while or((abs(x - x0 ) > e), (abs(y - y0) > e)) %пока точность не будет достигнута
x0 = x;
y0 = y;
x = (-0.4 - sin(y));  
y = cos(x+1)/2;
k = k + 1;
end
%вывод
disp('Задание 2:');
disp('Количество итераций:');
k   %количество итераций
x   %решения
y

%задание 1
A = [3 1 -1 1
    1 -4 1 -1
    -1 1 4 1
    1 2 1 -5]; 
b = [81; 21; -14; 29];
r=0;
disp('Решение с помощью функции Matlab:');
x = A\b % точное решение 
x0 = [1.4;1;2;0.5];
eps = 0.01;
n = length(b);
diagA = diag(A);
A = A-diag(diag(A));
% iteration
err = 10*eps;
while err > eps
  x = (b-A*x0)./diagA;
  err = norm(x-x0);
  x0 = x;
  r=r+1;
end
disp('Задание 1:');
x % result
disp('Кол-во итераций:');
r

