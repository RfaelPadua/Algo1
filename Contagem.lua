-- Define a função que conta de 0 até 1000 e imprime números ímpares

function contarImpares()
    for i = 0, 1000 do -- Conta de 0 a 1000     
        if i % 2 ~= 0 then -- Se o número for ímpar
            print(i) -- Imprime o número
        end
    end
end

-- Chama a função
contarImpares()