import { PrismaClient } from "@prisma/client";
import {
  GetServerSideProps,
  GetServerSidePropsContext,
  GetServerSidePropsResult,
} from "next";

export function withInstall<P>(fn: GetServerSideProps<P>): GetServerSideProps {
  return async (
    ctx: GetServerSidePropsContext
  ): Promise<GetServerSidePropsResult<P>> => {
    const prisma = new PrismaClient();

    const config = await prisma.config.findUnique({
      where: {
        id: 1,
      },
    });

    await prisma.$disconnect();

    if (config?.installed) {
      if (ctx.resolvedUrl === "/install") {
        return {
          redirect: {
            destination: "/",
            permanent: false,
          },
        };
      }
    } else {
      if (ctx.resolvedUrl !== "/install") {
        return {
          redirect: {
            destination: "/install",
            permanent: false,
          },
        };
      }
    }

    return await fn(ctx);
  };
}
