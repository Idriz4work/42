# Formatting Flags Documentation

## Overview of Format Specifier Flags

### `-` Flag (Alignment)
**Purpose:** Control field width alignment

| Behavior | Description |
|----------|-------------|
| With `-` flag | Left-justify the result within the field width |
| Default | Right-justify |

### `+` Flag (Sign Prefix)
**Purpose:** Control sign display for signed values

| Behavior | Description |
|----------|-------------|
| With `+` flag | Prefix the output value with a sign (+ or -) for signed types |
| Default | Sign appears only for negative signed values (-) |

### Blank ` ` Flag (Space Prefix)
**Purpose:** Handle positive signed value prefixing

| Behavior | Description |
|----------|-------------|
| With blank flag | Prefix the output value with a blank if the value is signed and positive |
| With both `+` and blank flags | `+` flag overrides blank flag |
| Default | No blank prefix |

### `#` Flag (Alternate Form)
**Purpose:** Modify output formatting for various types

| Format Type | Behavior |
|-------------|----------|
| With `o`, `x`, `X` | Prefix nonzero output with `0`, `0x`, or `0X` respectively |
| With `a`, `A`, `e`, `E`, `f`, `F` | Force decimal point in all cases |
| With `g`, `G` | Force decimal point and prevent truncation of trailing zeros |
| With `ls`, `S` | Measure precision in characters |
| With `p` | Convert pointer to hex digits (in teraspace environment) |

### `0` Flag (Zero Padding)
**Purpose:** Pad output with leading zeros

| Behavior | Description |
|----------|-------------|
| With `d`, `i`, `o`, `u`, `x`, `X`, `a`, `A`, `e`, `E`, `f`, `F`, `g`, `G` | Pad with leading zeros to field width |
| If precision specified for integer | Ignored |
| If `-` flag is specified | Ignored |
| Default | Space padding |

## Notes
- Flags can interact and override each other
- Specific behavior depends on the format specifier and context
- Always refer to language-specific documentation for exact implementation

## Best Practices
- Use flags intentionally
- Understand the specific behavior for each format type
- Test thoroughly to ensure desired output