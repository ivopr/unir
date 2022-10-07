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
  if (req.method === "POST") {
    const session = await getSession({ req });
    const productData = req.body as ProductData;

    if (session?.role !== "PROVIDER") {
      return res.status(401).json({ message: "not-a-provider" });
    }

    if (!session || !session.user || !session.user.email) {
      return res.status(401).json({ message: "unauthenticated" });
    }

    const product = await prisma.product.create({
      data: {
        name: productData.name,
        price: productData.price,
        quantity: productData.quantity,
        type: productData.type,
        provider: {
          connect: {
            email: session.user.email,
          },
        },
      },
    });

    return res.status(201).json(product);
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
