import { extendTheme } from "@chakra-ui/react";
import { GlobalStyleProps, mode } from "@chakra-ui/theme-tools";

export const theme = extendTheme({
	colors: {
		transparent: "transparent",
		current: "currentColor",
		black: "#000000",
		white: "#FFFFFF",

		whiteAlpha: {
			50: "rgba(255, 255, 255, 0.04)",
			100: "rgba(255, 255, 255, 0.06)",
			200: "rgba(255, 255, 255, 0.08)",
			300: "rgba(255, 255, 255, 0.16)",
			400: "rgba(255, 255, 255, 0.24)",
			500: "rgba(255, 255, 255, 0.36)",
			600: "rgba(255, 255, 255, 0.48)",
			700: "rgba(255, 255, 255, 0.64)",
			800: "rgba(255, 255, 255, 0.80)",
			900: "rgba(255, 255, 255, 0.92)"
		},

		blackAlpha: {
			50: "rgba(0, 0, 0, 0.04)",
			100: "rgba(0, 0, 0, 0.06)",
			200: "rgba(0, 0, 0, 0.08)",
			300: "rgba(0, 0, 0, 0.16)",
			400: "rgba(0, 0, 0, 0.24)",
			500: "rgba(0, 0, 0, 0.36)",
			600: "rgba(0, 0, 0, 0.48)",
			700: "rgba(0, 0, 0, 0.64)",
			800: "rgba(0, 0, 0, 0.80)",
			900: "rgba(0, 0, 0, 0.92)"
		},

		red: {
			100: "#FFE7D1",
			200: "#FFC9A4",
			300: "#FFA476",
			400: "#FF8054",
			500: "#FF451C",
			600: "#DB2914",
			700: "#B7130E",
			800: "#93080F",
			900: "#7A0513"
		},

		orange: {
			100: "#FFFBCC",
			200: "#FFF699",
			300: "#FFF066",
			400: "#FFEA3F",
			500: "#FFE100",
			600: "#DBBE00",
			700: "#B79D00",
			800: "#937D00",
			900: "#7A6500"
		},

		info: {
			100: "#CAFCF3",
			200: "#96FAF0",
			300: "#61F2EF",
			400: "#39DCE6",
			500: "#00B9D6",
			600: "#0090B8",
			700: "#006C9A",
			800: "#004E7C",
			900: "#003866"
		},

		green: {
			100: "#D3FAD2",
			200: "#A6F5AB",
			300: "#75E286",
			400: "#4FC56D",
			500: "#20A04D",
			600: "#17894A",
			700: "#107346",
			800: "#0A5C3F",
			900: "#064C3A"
		},

		primary: {
			100: "#D9E6FD",
			200: "#B4CBFC",
			300: "#8DACF6",
			400: "#6E91EC",
			500: "#4169E1",
			600: "#2F50C1",
			700: "#203AA2",
			800: "#142782",
			900: "#0C1A6C"
		}
	},
	components: {
		Toast: {
			baseStyle: {
				containerStyle: {
					width: "100%"
				}
			}
		}
	},
	config: {
		initialColorMode: "light",
		useSystemColorMode: false
	},
	fonts: {
		heading: "Poppins",
		body: "Poppins"
	},
	styles: {
		global: (props: GlobalStyleProps) => ({
			body: {
				bg: mode("white", "gray.800")(props)
			}
		})
	}
});