pkg load image;

m = [
  -1 -1 -1;
  -1  8 -1;
  -1 -1 -1;
];

f = imread("images/regiao.tif");

g = conv2(f, m);

figure, imshow(f);
figure, imshow(g);

