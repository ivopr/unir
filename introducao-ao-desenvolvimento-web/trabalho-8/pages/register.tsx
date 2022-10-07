import {
  Anchor,
  Button,
  Container,
  Divider,
  Paper,
  PasswordInput,
  Select,
  Text,
  TextInput,
  Title,
} from "@mantine/core";
import { useForm, zodResolver } from "@mantine/form";
import { useNotifications } from "@mantine/notifications";
import { GetServerSideProps } from "next";
import Head from "next/head";
import NextLink from "next/link";
import { useRouter } from "next/router";
import { signIn } from "next-auth/react";
import { useTranslation } from "next-i18next";
import { serverSideTranslations } from "next-i18next/serverSideTranslations";
import { BrandGoogle, UserPlus } from "tabler-icons-react";
import { z } from "zod";

import { withSSRGuest } from "../hocs/with-ssr-guest";
import { usePostCreateAccountMutation } from "../store/api/account";

const RegisterSchema = z.object({
  email: z
    .string()
    .nonempty({ message: "What is your email?" })
    .email({ message: "This must be a valid email" }),
  name: z.string().nonempty({ message: "You must provide your name " }),
  password: z
    .string()
    .nonempty({ message: "You surely set a password when creating your account" })
    .min(5, { message: "Your password must be at least 5 characters long" }),
  role: z.string().nonempty({ message: "You must have a role" }),
  roleGuard: z.string(),
  cnpj: z.string(),
  phone: z.string(),
  address: z.string(),
});

export default function Register(): JSX.Element {
  const [createAccount] = usePostCreateAccountMutation();
  const form = useForm<z.infer<typeof RegisterSchema>>({
    schema: zodResolver(RegisterSchema),
    initialValues: {
      email: "",
      name: "",
      password: "",
      role: "USER",
      roleGuard: "",
      address: "",
      cnpj: "",
      phone: "",
    },
  });
  const notifications = useNotifications();
  const router = useRouter();

  const commonTL = useTranslation("common");
  const registerTL = useTranslation("register");

  const onSubmit = form.onSubmit(
    async ({ email, name, password, role, roleGuard, address, cnpj, phone }) => {
      // Handle your credentials register here
      await createAccount({ email, name, password, role, roleGuard, address, cnpj, phone })
        .unwrap()
        .then(async (data) => {
          notifications.showNotification({
            message: `Created account for ${data.name}`,
            color: "green",
          });

          await signIn("credentials", { email, password, redirect: false }).then(() =>
            router.push("/account")
          );
        })
        .catch(() => {
          notifications.showNotification({
            message: `Account not created`,
            color: "red",
          });
        });
    }
  );

  return (
    <Container size="xs">
      <Head>
        <title>
          {registerTL.t("title")} &bull; {commonTL.t("app-name")}
        </title>
      </Head>
      <Title align="center">{registerTL.t("title")}</Title>
      <Text color="dimmed" size="sm" align="center" mt={5}>
        {registerTL.t("is-registered")}
        <NextLink href="/login" passHref>
          <Anchor<"a"> ml={3} size="sm">
            {registerTL.t("login")}
          </Anchor>
        </NextLink>
      </Text>

      <Paper withBorder shadow="md" p={30} mt={30} radius="md">
        <Button
          color="blue"
          fullWidth
          leftIcon={<BrandGoogle size={18} />}
          onClick={() => signIn("google", { redirect: false })}
        >
          {registerTL.t("with-google")}
        </Button>
        <Divider mt="sm" label={registerTL.t("or-with")} labelPosition="center" />
        <form onSubmit={onSubmit}>
          <TextInput label={registerTL.t("fields.email")} {...form.getInputProps("email")} />
          <TextInput mt="md" label={registerTL.t("fields.name")} {...form.getInputProps("name")} />
          <PasswordInput
            mt="md"
            label={registerTL.t("fields.password")}
            {...form.getInputProps("password")}
          />
          <Select
            data={["USER", "PROVIDER", "ADMIN"]}
            label={registerTL.t("fields.role")}
            mt="md"
            {...form.getInputProps("role")}
          />
          {form.values.role === "PROVIDER" && (
            <>
              <TextInput
                label={registerTL.t("fields.cnpj")}
                mt="md"
                {...form.getInputProps("cnpj")}
              />
              <TextInput
                label={registerTL.t("fields.phone")}
                mt="md"
                {...form.getInputProps("phone")}
              />
              <TextInput
                label={registerTL.t("fields.address")}
                mt="md"
                {...form.getInputProps("address")}
              />
            </>
          )}
          {form.values.role === "ADMIN" && (
            <TextInput
              label={registerTL.t("fields.role-check")}
              mt="md"
              {...form.getInputProps("roleGuard")}
            />
          )}
          <Button type="submit" leftIcon={<UserPlus size={18} />} fullWidth mt="xl">
            {registerTL.t("title")}
          </Button>
        </form>
      </Paper>
    </Container>
  );
}

export const getServerSideProps: GetServerSideProps = withSSRGuest(async (context) => {
  return {
    props: {
      ...(await serverSideTranslations(context.locale ?? "en", ["common", "register"])),
    },
  };
});
