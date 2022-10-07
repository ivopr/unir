pkg load image;

f = imread("images/wirebond_mask.tif");

m = [
  -1 -1 -1;
  -1  8 -1;
  -1 -1 -1;
];

g = imfilter(im2double(f), m);
figure, imshow(g);

g = abs(g);
figure, imshow(g);

g = imfilter(im2double(f), m);
g(g < 0) = 0;
T = max(g(:));
g = g >= T;
figure, imshow(g);

g = imfilter(im2double(f), m);
g = g >= T;
figure, imshow(g);
