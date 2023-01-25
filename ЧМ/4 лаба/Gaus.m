%format long;

disp('Метод Гаусса');

%Матрица коэффициентов
A = [1 -2 3 3           % x1 - 2x2 + 3x3 + 3x4
    1 3 -4 3            % x1 + 3x2 - 4x3 + 3x4
    2 3 -4 5            % 2x1 + 3x2 - 4x3 + 5x4
    3 -5 7 7];          % 3x1 - 5x2 + 7x3 + 7x4
%Матрица свободных членов
B = [2                  % = 2
    2                   % = 2
    3                   % = 3 
    4];                 % = 4

proverka=det(A); % определитель матрицы

if(proverka ~= 0 && A(1,1) ~= 0) % Является ли матрица невырожденной

[numRows, numCols] = size(A); %Размерность матрицы по строкам и столбцам

matrix = [ A B];
disp('Дополненная матрица');
disp(matrix);

i = 2; %С какой строки начинаем 

m = 2;

j = 1;

%Прохожение по строкам 2-4
while i < 5
    for i=m:1:numRows
        matrix(i,:)= matrix(i,:)- matrix(j,:)/matrix(j,j)*matrix(i,j);
    end
    % переход на новую строку => меняем переменную m
    m = m + 1;
   
    j = j + 1;
end

disp('Матрица после преобразований');
disp(matrix);

disp('Решение');
x(4) = matrix(4,5)/matrix(4,4);
x(3) = (matrix(3,5) - matrix(3,4) * x(4)) / matrix(3,3);
x(2) = (matrix(2,5) - matrix(2,4) * x(4) - matrix(2,3) * x(3)) / matrix(2,2);
x(1) = (matrix(1,5) - matrix(1,4) * x(4) - matrix(1,3) * x(3) - matrix(1,2) * x(2)) / matrix(1,1);
X = [x(1), x(2), x(3), x(4)];
disp('Решение СЛАУ с помощью метода Гаусса');
disp(X);
end;
