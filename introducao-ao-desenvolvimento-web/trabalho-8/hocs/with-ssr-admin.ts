import { GetServerSideProps, GetServerSidePropsContext, GetServerSidePropsResult } from "next";
import { getSession } from "next-auth/react";

export function withSSRAdmin<P>(fn: GetServerSideProps<P>): GetServerSideProps {
  return async (context: GetServerSidePropsContext): Promise<GetServerSidePropsResult<P>> => {
    const session = await getSession(context);

    if (session && session.role === "ADMIN") {
      try {
        return await fn(context);
      } catch (err) {
        return {
          props: {} as P,
        };
      }
    }

    return {
      redirect: {
        destination: "/login",
        permanent: false,
      },
    };
  };
}
