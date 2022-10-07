import {
  FormControl,
  FormErrorMessage,
  FormLabel,
  Input as ChakraInput,
  InputProps,
  useColorModeValue,
} from "@chakra-ui/react";
import { forwardRef, ForwardRefRenderFunction } from "react";
import { FieldError } from "react-hook-form";

interface FormInputProps extends InputProps {
  label?: string;
  name: string;
  error?: FieldError;
}

const InputBase: ForwardRefRenderFunction<HTMLInputElement, FormInputProps> = (
  { name, error = null, label, ...rest },
  ref
): JSX.Element => {
  return (
    <FormControl isInvalid={!!error}>
      {!!label && (
        <FormLabel id={name} htmlFor={name}>
          {label}
        </FormLabel>
      )}
      <ChakraInput
        _focus={{
          borderColor: "primary.500",
          backgroundColor: useColorModeValue("gray.200", "gray.900"),
        }}
        _hover={{
          backgroundColor: useColorModeValue("gray.200", "gray.900"),
        }}
        backgroundColor={useColorModeValue("gray.200", "gray.900")}
        id={name}
        name={name}
        padding={1}
        ref={ref}
        rounded="lg"
        variant="filled"
        {...rest}
      />

      {!!error && <FormErrorMessage>{error.message}</FormErrorMessage>}
    </FormControl>
  );
};

export const Input = forwardRef(InputBase);
