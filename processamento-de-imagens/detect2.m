pkg load image;

f = imread("images/turbina.tif");

m = [
  -1 -1 -1;
  -1  8 -1;
  -1 -1 -1;
] * -1;

g = abs(imfilter(im2double(f), m));
T = max(g(:));

g = g >= T;

figure, imshow(g);
