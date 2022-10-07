a = [1 0 1 1 0 1];
b = [1 1 0 1 1 0 1 1];
c = [0 1 1 0 1];
d = [0 1 1 1 1 1 1 1 0 1];

B2D = @(a) sum(a.*(2.^(size(a,2)-1:-1:0)),2);

a = num2str(a);
a(isspace(a)) = '';
B2D(a)

b = num2str(b);
b(isspace(b)) = '';
B2D(b)

c = num2str(c);
c(isspace(c)) = '';
B2D(c)

d = num2str(d);
d(isspace(d)) = '';
B2D(d)