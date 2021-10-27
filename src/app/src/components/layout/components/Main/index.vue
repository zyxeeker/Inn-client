<template>
    <div style="height:100%;width:100%;">
        <n-layout-header style="height:100px;padding: 12px;" bordered>
            <n-page-header subtitle="TEST-ID-20211027">
                <template #title>
                    <a href="" style="text-decoration: none; color: inherit;">{{ $route.params.title }}</a>
                </template>
                <template #header>
                    <n-breadcrumb>
                        <n-breadcrumb-item>TEST</n-breadcrumb-item>
                        <n-breadcrumb-item>TEST</n-breadcrumb-item>
                        <n-breadcrumb-item>TEST</n-breadcrumb-item>
                        <n-breadcrumb-item>TEST</n-breadcrumb-item>
                    </n-breadcrumb>
                </template>
                <template #avatar>
                    <n-avatar :style="{color: 'black',backgroundColor: 'transparent'}">
                        <n-icon>
                            <Signature/>
                        </n-icon>
                    </n-avatar>
                </template>
                <template #extra>
                    <n-space>
                        <n-button>TEST</n-button>
                        <n-dropdown :options="options" placement="bottom-start">
                            <n-button :bordered="false" style="padding: 0 4px">···</n-button>
                        </n-dropdown>
                    </n-space>
                </template>
            </n-page-header>
        </n-layout-header>
        <n-layout position="absolute"
                  style="top: 100px;bottom:68px;padding-left: 20px;"
                  :native-scrollbar="false"
                  ref="container"
        >
            <Title/>
            <Content/>
        </n-layout>
    </div>
</template>

<script>
import {defineComponent} from 'vue'
import {Signature} from "@vicons/fa"
import Title from "@/components/view/Title";
import Content from "@/components/view/Content";

export default defineComponent({
    name: "Main",
    setup() {
        return {
            options: [
                {
                    label: 'TEST',
                    key: '1'
                },
                {
                    label: 'TEST',
                    key: '2'
                },
                {
                    label: 'TEST',
                    key: '3'
                }
            ]
        }
    },
    components: {
        Content,
        Title,
        Signature
    }
})
</script>

<style scoped>

</style>
