// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import { User } from "@prisma/client";
import type { NextApiRequest, NextApiResponse } from "next";

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<User[] | { message: string } | undefined>
): Promise<void> {
  if (req.method === "GET") {
    const accounts = await prisma?.user.findMany();

    return res.status(201).json(accounts);
  }
  return res.status(405).json({
    message: `You can't ${req.method} this route.`,
  });
}
