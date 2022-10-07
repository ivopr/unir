import { Button, useColorModeValue } from "@chakra-ui/react";

interface ItemProps {
  isCurrent?: boolean;
  number: number;
  onPageChange: (page: number) => void;
}

export function Item({
  isCurrent = false,
  number,
  onPageChange,
}: ItemProps): JSX.Element {
  const bgHover = useColorModeValue("gray.400", "gray.600");
  const bg = useColorModeValue("gray.300", "gray.700");

  if (isCurrent) {
    return (
      <Button
        _disabled={{
          bg: "primary.500",
          cursor: "default",
        }}
        _hover={{
          bg: "primary.500",
        }}
        color="white"
        colorScheme="primary"
        disabled
        fontSize="xs"
        rounded="lg"
        size="sm"
        width={4}
      >
        {number}
      </Button>
    );
  }

  return (
    <Button
      _hover={{
        bg: bgHover,
      }}
      bg={bg}
      fontSize="xs"
      onClick={() => onPageChange(number)}
      rounded="lg"
      size="sm"
      width={4}
    >
      {number}
    </Button>
  );
}
