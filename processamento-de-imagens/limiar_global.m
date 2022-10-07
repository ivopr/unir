pkg load image;

f = imread("images/polymersomes.tif");
count = 0;
T = mean2(f);
done = false;

while(~done)
  count = count + 1;
  g = f > T;
  Tnext = 0.5 * (mean(f(g)) + mean(f(~g)));
  done = abs(T - Tnext) < 0.5;
  T = Tnext;
endwhile

f(f > T) = 255;
f(f <= T) = 0;

imshow(f);
