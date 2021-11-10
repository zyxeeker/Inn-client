<template>
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
</template>

<script>
import {Signature} from "@vicons/fa"

export default {
    name: "MainHeader",
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
        Signature
    }
}
</script>

<style scoped>

</style>
