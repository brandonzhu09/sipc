#pragma once

/*
 * This include is for convenience when defining algorithms spanning
 * the TIP type hierarchy, e.g., visitors.
 *
 * It should be used sparingly as it introduces coupling to the entire
 * TIP type hierarchy.
 */

#include "TipAbsentField.h"
#include "TipAlpha.h"
#include "TipFunction.h"
#include "TipInt.h"
#include "TipMu.h"
#include "TipRecord.h"
#include "TipRef.h"
#include "TipType.h"
#include "TipVar.h"

#include "TipBool.h"
#include "TipArr.h"
