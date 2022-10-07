// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import { User } from "@prisma/client";
import type { NextApiRequest, NextApiResponse } from "next";

import { prisma } from "../../../services/prisma";

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<User[] | { message: string } | undefined>
): Promise<void> {
  if (req.method === "GET") {
    const accounts = await prisma.user.findMany();

    if (accounts.length > 0) {
      accounts.sort((a, b) => {
        if (a.name === null || b.name === null) {
          return 0;
        }

        if (a.name < b.name) {
          return -1;
        }

        if (a.name > b.name) {
          return 1;
        }

        return 0;
      });
    }

    return res.status(201).json(accounts);
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
