// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import { User } from "@prisma/client";
import { hash } from "bcryptjs";
import type { NextApiRequest, NextApiResponse } from "next";

type AccountCredentials = {
  name: string;
  email: string;
  password: string;
  role: "USER" | "VIP_USER" | "ADMIN";
  roleGuard: string;
};

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<User | { message: string } | undefined>
): Promise<void> {
  if (req.method === "POST") {
    const accountCredentials = req.body as AccountCredentials;

    const password = await hash(accountCredentials.password, 8);

    if (
      await prisma?.user.findUnique({
        where: {
          email: accountCredentials.email,
        },
      })
    ) {
      return res.status(400).json({ message: "already-exists" });
    }

    if (accountCredentials.role !== "USER") {
      if (accountCredentials.roleGuard !== "check") {
        return res.status(401).json({ message: "no-permission" });
      }
    }

    const account = await prisma?.user.create({
      data: {
        email: accountCredentials.email,
        password,
        name: accountCredentials.name,
        role: accountCredentials.role,
      },
    });

    return res.status(201).json(account);
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
