import "jspdf-autotable";

import { Product, User } from "@prisma/client";
import JSPDF from "jspdf";

// define a generatePDF function that accepts a tickets argument
export const generateProductsReport = (products: Product[]): void => {
  // initialize jsPDF
  const doc = new JSPDF();

  // define the columns we want and their titles
  const tableColumn = ["Name", "Price", "Quantity", "Type", "Provider Email", "Created At"];
  // define an empty array of rows
  const tableRows: (string | number | null)[][] = [];

  // for each ticket pass all its data into an array
  products.forEach((product) => {
    const productData = [
      product.name,
      Intl.NumberFormat("pt-BR", {
        currency: "BRL",
        style: "currency",
      }).format(product.price / 100),
      product.quantity,
      product.type,
      product.providerEmail,
      Intl.DateTimeFormat("pt-BR", {
        dateStyle: "medium",
      }).format(new Date(product.createdAt)),
    ];
    // push each tickcet's info into a row
    tableRows.push(productData);
  });

  // startY is basically margin-top
  doc.autoTable(tableColumn, tableRows, { startY: 20 });
  const date = Date().split(" ");
  // we use a date string to generate our filename.
  const dateStr = date[0] + date[1] + date[2] + date[3] + date[4];
  // ticket title. and margin-top + margin-left
  doc.text("Products Report.", 14, 15);
  // we define the name of our PDF file.
  doc.save(`products_report_${dateStr}.pdf`);
};

export const generateUsersReport = (users: User[]): void => {
  // initialize jsPDF
  const doc = new JSPDF();

  // define the columns we want and their titles
  const tableColumn = ["Name", "Email", "Role", "CNPJ", "Phone", "Created At"];
  // define an empty array of rows
  const tableRows: (string | null)[][] = [];

  // for each ticket pass all its data into an array
  users.forEach((user) => {
    const userData = [
      user.name,
      user.email,
      user.role,
      user.cnpj,
      user.phone,
      Intl.DateTimeFormat("pt-BR", {
        dateStyle: "medium",
      }).format(new Date(user.createdAt)),
    ];
    // push each tickcet's info into a row
    tableRows.push(userData);
  });

  // startY is basically margin-top
  doc.autoTable(tableColumn, tableRows, { startY: 20 });
  const date = Date().split(" ");
  // we use a date string to generate our filename.
  const dateStr = date[0] + date[1] + date[2] + date[3] + date[4];
  // ticket title. and margin-top + margin-left
  doc.text("Users Report.", 14, 15);
  // we define the name of our PDF file.
  doc.save(`users_report_${dateStr}.pdf`);
};
