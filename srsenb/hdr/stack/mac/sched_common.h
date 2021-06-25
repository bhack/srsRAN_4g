/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2021 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSRAN_SCHED_COMMON_H
#define SRSRAN_SCHED_COMMON_H

/**
 * File used for all functions and types common to the LTE and NR schedulers
 */

namespace srsenb {

/// Error code of alloc attempt
enum class alloc_result {
  success,
  sch_collision,
  no_cch_space,
  no_sch_space,
  no_rnti_opportunity,
  invalid_grant_params,
  invalid_coderate,
  no_grant_space,
  other_cause
};
inline const char* to_string(alloc_result result)
{
  switch (result) {
    case alloc_result::success:
      return "success";
    case alloc_result::sch_collision:
      return "Collision with existing SCH allocations";
    case alloc_result::other_cause:
      return "error";
    case alloc_result::no_cch_space:
      return "No space available in PUCCH or PDCCH";
    case alloc_result::no_sch_space:
      return "Requested number of PRBs not available";
    case alloc_result::no_rnti_opportunity:
      return "rnti cannot be allocated (e.g. already allocated, no data, meas gap collision, carrier inactive, etc.)";
    case alloc_result::invalid_grant_params:
      return "invalid grant arguments (e.g. invalid prb mask)";
    case alloc_result::invalid_coderate:
      return "Effective coderate exceeds threshold";
    case alloc_result::no_grant_space:
      return "Max number of allocations reached";
    default:
      break;
  }
  return "unknown error";
}

} // namespace srsenb

#endif // SRSRAN_SCHED_COMMON_H
