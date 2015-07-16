/*
 * Copyright (C) 2005, 2006, 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SKY_ENGINE_CORE_EDITING_INSERTINTOTEXTNODECOMMAND_H_
#define SKY_ENGINE_CORE_EDITING_INSERTINTOTEXTNODECOMMAND_H_

#include "sky/engine/core/editing/EditCommand.h"

namespace blink {

class Text;

class InsertIntoTextNodeCommand final : public SimpleEditCommand {
public:
    static PassRefPtr<InsertIntoTextNodeCommand> create(PassRefPtr<Text> node, unsigned offset, const String& text)
    {
        return adoptRef(new InsertIntoTextNodeCommand(node, offset, text));
    }

private:
    InsertIntoTextNodeCommand(PassRefPtr<Text> node, unsigned offset, const String& text);

    virtual void doApply() override;
    virtual void doUnapply() override;

    RefPtr<Text> m_node;
    unsigned m_offset;
    String m_text;
};

} // namespace blink

#endif  // SKY_ENGINE_CORE_EDITING_INSERTINTOTEXTNODECOMMAND_H_
