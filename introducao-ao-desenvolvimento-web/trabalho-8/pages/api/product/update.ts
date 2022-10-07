// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import { Product } from "@prisma/client";
import type { NextApiRequest, NextApiResponse } from "next";
import { getSession } from "next-auth/react";

import { prisma } from "../../../services/prisma";

type ProductData = {
  quantity: number;
  name: string;
  price: number;
  type: string;
};

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<Product | { message: string } | undefined>
): Promise<void> {
  if (req.method === "PUT") {
    const { productId } = req.query;
    const productData = req.body as ProductData;

    const session = await getSession({ req });

    if (!session) {
      return res.status(401).json({ message: "unauthenticated" });
    }

    const product = await prisma.product.findFirst({
      where: {
        id: productId as string,
      },
    });

    if (!product) {
      return res.status(400).json({ message: "product-not-found" });
    }

    if (session.role !== "ADMIN" && session.user?.email !== product.providerEmail) {
      return res.status(401).json({ message: "unauthorized" });
    }

    const updatedProduct = await prisma.product.update({
      where: {
        id: productId as string,
      },
      data: {
        name: productData.name,
        price: productData.price,
        quantity: productData.quantity,
        type: productData.type,
      },
    });

    return res.json(updatedProduct);
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
