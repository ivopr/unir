// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import type { NextApiRequest, NextApiResponse } from "next";
import { getSession } from "next-auth/react";

import { prisma } from "../../../services/prisma";

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<{ message: string } | undefined>
): Promise<void> {
  if (req.method === "POST") {
    const { accountId } = req.query;
    const session = await getSession({ req });

    if (!session || session.role !== "ADMIN") {
      return res.status(401).json({ message: "unauthenticated" });
    }

    if (accountId === session.id) {
      return res.status(401).json({ message: "cannot-deactivate-yourself" });
    }

    const account = await prisma.user.findFirst({
      where: {
        id: accountId as string,
      },
    });

    if (!account) {
      return res.status(400).json({ message: "account-not-found" });
    }

    await prisma.user.update({
      where: {
        id: accountId as string,
      },
      data: {
        active: !account.active,
      },
    });

    return res.json({ message: "toggled" });
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
