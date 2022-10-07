import { NextApiRequest, NextApiResponse } from "next";

import { prisma } from "../../../services/prisma";

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse
): Promise<void> {
  const { method } = req;

  switch (method) {
    case "GET": {
      const { page, skip } = req.query;

      const totalContacts = await prisma.contact.count();
      const contacts = await prisma.contact.findMany({
        skip: (Number(page) - 1) * 10,
        take: Number(skip),
        orderBy: [
          {
            createdAt: "desc",
          },
        ],
      });

      res.status(200).json({ contacts, totalContacts });
      break;
    }
    case "POST": {
      const {
        body: { id, name, email, number, obs, cpf },
      } = req;

      const totalContacts = await prisma.contact.findMany();
      const contact = await prisma.contact.upsert({
        create: {
          name,
          email,
          number,
          obs,
          cpf,
        },
        update: {
          name,
          email,
          number,
          obs,
          cpf,
        },
        where: {
          id: Number(
            id ?? totalContacts.length > 0
              ? totalContacts[totalContacts.length - 1].id + 1
              : 1
          ),
        },
      });

      res.status(200).json(contact);
      break;
    }
    case "DELETE": {
      const deletedContacts = await prisma.contact.deleteMany();
      res.status(200).json(deletedContacts);
      break;
    }
    default: {
      res.setHeader("Allow", ["GET", "POST", "DELETE"]);
      res.status(405).end(`Method ${method} Not Allowed`);
    }
  }
}
