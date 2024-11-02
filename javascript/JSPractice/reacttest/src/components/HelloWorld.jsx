import styled from 'styled-components';

export const HelloWorld = () => {
    return (
        <SContainer>
            <SH1>Hello World!</SH1>
        </SContainer>
    );
};

const SContainer = styled.div`
    background-color: #cd1c1c;
    &:hover {
        background-color: #111;
    }
`;

const SH1 = styled.h1`
    color: #fff;
    font-size: center;
`;