import { Button, Group, Modal, Select, TextInput } from "@mantine/core";
import { useForm, zodResolver } from "@mantine/form";
import { useNotifications } from "@mantine/notifications";
import { User } from "@prisma/client";
import { useTranslation } from "next-i18next";
import { useState } from "react";
import { Pencil } from "tabler-icons-react";
import { z } from "zod";

import { useGetAllAccountsQuery, usePutUpdateAccountMutation } from "../../store/api/account";

const EditAccountSchema = z.object({
  email: z
    .string()
    .nonempty({ message: "What is your email?" })
    .email({ message: "This must be a valid email" }),
  name: z.string().nonempty({ message: "You must provide your name " }),
  role: z.string().nonempty({ message: "You must have a role" }),
  cnpj: z.string(),
  phone: z.string(),
  address: z.string(),
});

type EditAccountModal = {
  user: User;
};

export function EditUserModal({ user }: EditAccountModal): JSX.Element {
  const [opened, setOpened] = useState(false);
  const [updateAccount] = usePutUpdateAccountMutation();
  const form = useForm<z.infer<typeof EditAccountSchema>>({
    schema: zodResolver(EditAccountSchema),
    initialValues: {
      email: user.email as string,
      name: user.name as string,
      role: user.role,
      address: user.address as string,
      cnpj: user.cnpj as string,
      phone: user.phone as string,
    },
  });
  const notifications = useNotifications();
  const accountsTL = useTranslation("accounts");

  const { refetch } = useGetAllAccountsQuery(null);

  const onSubmit = form.onSubmit(async ({ name, address, cnpj, email, phone, role }) => {
    // Handle your credentials login here
    await updateAccount({ id: user.id, name, email, role, address, cnpj, phone })
      .unwrap()
      .then((data) => {
        notifications.showNotification({
          message: `Product ${data.name} updated`,
          color: "green",
        });

        refetch();
        setOpened(false);
      })
      .catch(() => {
        notifications.showNotification({
          message: "There was an error creating your product",
          color: "red",
        });
      });
  });

  return (
    <>
      <Modal
        centered
        opened={opened}
        onClose={() => setOpened(false)}
        title={accountsTL.t("modal.title")}
      >
        <form onSubmit={onSubmit}>
          <TextInput label={accountsTL.t("modal.name")} {...form.getInputProps("name")} />
          <TextInput label={accountsTL.t("modal.email")} mt="md" {...form.getInputProps("email")} />
          <Select
            data={["USER", "PROVIDER", "ADMIN"]}
            label={accountsTL.t("modal.role")}
            mt="md"
            {...form.getInputProps("role")}
          />
          {form.values.role === "PROVIDER" && (
            <>
              <TextInput
                label={accountsTL.t("modal.cnpj")}
                mt="md"
                {...form.getInputProps("cnpj")}
              />
              <TextInput
                label={accountsTL.t("modal.phone")}
                mt="md"
                {...form.getInputProps("phone")}
              />
              <TextInput
                label={accountsTL.t("modal.address")}
                mt="md"
                {...form.getInputProps("address")}
              />
            </>
          )}
          <Button type="submit" leftIcon={<Pencil size={18} />} fullWidth mt="xl">
            {accountsTL.t("modal.title")}
          </Button>
        </form>
      </Modal>

      <Group position="center">
        <Button color="blue" onClick={() => setOpened(true)}>
          <Pencil />
        </Button>
      </Group>
    </>
  );
}
