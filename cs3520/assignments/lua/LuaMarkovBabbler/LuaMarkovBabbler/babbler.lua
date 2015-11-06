start = function(file, num_words, n)
    local contents = load_file(file)
    local tokens, word_count = tokenize(contents, n)
    local shingles = shingle(tokens, word_count, n)
    local table = make_table(shingles)
    babble(shingles[math.random(#shingles)], table, num_words)
end

tokenize = function(contents, n)
    local tokens = {}
    offset = 0
    local current_token = 1
    local token = nil

    while offset < string.len(contents) - 1 do
        token, offset = get_token(contents, offset)
        if token ~= '' then
            tokens[current_token] = token
            current_token = current_token + 1
        end
    end

    local word_count = #tokens

    for i = 1, n do
        tokens[current_token] = tokens[i]
        current_token = current_token + 1
    end

    return tokens, word_count
end

shingle = function(tokens, word_count, n)
    local ngrams = {}
    local current = 1
    for i = 1, word_count do
        local gram = {}
        local gram_index = 1
        for j = i, i+n-1 do
            gram[gram_index] = tokens[j]
            gram_index = gram_index + 1
        end
        ngrams[current] = gram
        current = current + 1
    end
    return ngrams
end

make_table = function(shingles)
    local t = {}
    for i = 1, #shingles do
        local tokens = shingles[i]

        -- key is all but the last token strung together
        local keys = {}
        for i = 1, #tokens - 1 do
            keys[i] = tokens[i]
        end
        local key = table.concat(keys, " ")

        -- suffix is the last token
        local suffix = tokens[#tokens]

        local suffix_list = {suffix}
        -- key might already exist in the table
        if t[key] ~= nil then
            suffix_list = t[key]
            -- append the new suffix
            suffix_list[#suffix_list + 1] = suffix
        end

        t[key] = suffix_list
    end

    return t
end

babble = function(start, t, num_words)
    local ngram = start
    for i = 1, num_words do
        -- throw away the first token.
        local keys = {}
        for j = 1, #ngram - 1 do
            keys[j] = ngram[j+1]
        end
        ngram = keys
        local prefix = table.concat(keys, " ")
        local candidates = t[prefix]
        local suffix = candidates[math.random(#candidates)]
        ngram[#ngram + 1] = suffix

        print(suffix)
    end
end
