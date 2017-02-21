// Copyright 2017 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
#pragma once

namespace document {
class DocumentType;
class DocumentTypeRepo;
}
namespace search { class IAttributeManager; }

namespace proton {

class IDocumentDBReferentRegistry;

/**
 * Class that for a given document db resolves all references to parent document dbs:
 *   1) Connects all reference attributes to gid mappers of parent document dbs.
 */
class DocumentDBReferenceResolver {
private:
    const IDocumentDBReferentRegistry &_registry;
    const search::IAttributeManager &_attrMgr;
    const document::DocumentType &_thisDocType;

    void connectReferenceAttributesToGidMapper();

public:
    DocumentDBReferenceResolver(const IDocumentDBReferentRegistry &registry,
                                const search::IAttributeManager &attrMgr,
                                const document::DocumentType &thisDocType);

    void resolve();
};

}