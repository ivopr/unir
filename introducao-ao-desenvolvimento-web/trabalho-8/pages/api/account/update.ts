// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import { User } from "@prisma/client";
import type { NextApiRequest, NextApiResponse } from "next";
import { getSession } from "next-auth/react";

import { prisma } from "../../../services/prisma";

type UserData = {
  name: string;
  email: string;
  password: string;
  role: "USER" | "PROVIDER" | "ADMIN";
  roleGuard?: string;
  cnpj?: string;
  address?: string;
  phone?: string;
};

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<User | { message: string } | undefined>
): Promise<void> {
  if (req.method === "PUT") {
    const { userId } = req.query;
    const userData = req.body as UserData;

    const session = await getSession({ req });

    if (!session) {
      return res.status(401).json({ message: "unauthenticated" });
    }

    const user = await prisma.user.findFirst({
      where: {
        id: userId as string,
      },
    });

    if (!user) {
      return res.status(400).json({ message: "user-not-found" });
    }

    if (session.role !== "ADMIN") {
      return res.status(401).json({ message: "unauthorized" });
    }

    const updatedUser = await prisma.user.update({
      where: {
        id: userId as string,
      },
      data: {
        cnpj: userData.cnpj,
        address: userData.address,
        email: userData.email,
        name: userData.name,
        phone: userData.phone,
        role: userData.role,
      },
    });

    return res.json(updatedUser);
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
