/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Analog switch is open (disabled) */
#define IOCON_PIO_ASW_DI 0x00u
/*!
 * @brief Enables digital function */
#define IOCON_PIO_DIGITAL_EN 0x0100u
/*!
 * @brief Selects pin function 1 */
#define IOCON_PIO_FUNC1 0x01u
/*!
 * @brief Selects pin function 6 */
#define IOCON_PIO_FUNC6 0x06u
/*!
 * @brief Input function is not inverted */
#define IOCON_PIO_INV_DI 0x00u
/*!
 * @brief No addition pin function */
#define IOCON_PIO_MODE_INACT 0x00u
/*!
 * @brief Open drain is disabled */
#define IOCON_PIO_OPENDRAIN_DI 0x00u
/*!
 * @brief Standard mode, output slew rate control is enabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_10_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 3. */
#define PIO1_10_FUNC_ALT3 0x03u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_22_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 3. */
#define PIO1_22_FUNC_ALT3 0x03u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_6_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 3. */
#define PIO1_6_FUNC_ALT3 0x03u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_7_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 3. */
#define PIO1_7_FUNC_ALT3 0x03u

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M33 (Core #0) */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
