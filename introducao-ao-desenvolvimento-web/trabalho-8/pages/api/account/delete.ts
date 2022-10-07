// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import type { NextApiRequest, NextApiResponse } from "next";
import { getSession } from "next-auth/react";

import { prisma } from "../../../services/prisma";

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<{ message: string } | undefined>
): Promise<void> {
  if (req.method === "DELETE") {
    const { accountId } = req.query;
    const session = await getSession({ req });

    if (!session) {
      return res.status(401).json({ message: "unauthenticated" });
    }

    const account = await prisma.user.findFirst({
      where: {
        id: accountId as string,
      },
    });

    if (!account) {
      return res.status(400).json({ message: "account-not-found" });
    }

    if (session.role !== "ADMIN") {
      return res.status(401).json({ message: "unauthorized" });
    }

    if (accountId === session.id) {
      return res.status(401).json({ message: "cannot-delete-yourself" });
    }

    await prisma.user.delete({
      where: {
        id: accountId as string,
      },
    });

    return res.json({ message: "deleted" });
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
