// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import { Product } from "@prisma/client";
import type { NextApiRequest, NextApiResponse } from "next";

import { prisma } from "../../../services/prisma";

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<Product[] | { message: string } | undefined>
): Promise<void> {
  if (req.method === "GET") {
    const { email } = req.query;

    if (email) {
      const products = await prisma.product.findMany({
        where: {
          providerEmail: email as string,
        },
      });

      return res.status(200).json(products);
    }

    const products = await prisma.product.findMany();

    return res.status(201).json(products);
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
